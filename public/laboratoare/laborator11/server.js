const express = require('express');
const jwt = require('jsonwebtoken');
const bodyParser = require('body-parser');

const app = express();
const PORT = 3000;
const SECRET_KEY = 'your_secret_key';

// Database mock-up
const users = {};

app.use(bodyParser.json());

// Route for user registration
app.post('/register', (req, res) => {
    const { username, password } = req.body;
    users[username] = password;
    res.json({ message: 'User registered successfully' });
});

// Route for user login and token generation
app.post('/login', (req, res) => {
    const { username, password } = req.body;
    if (users[username] === password) {
        const token = jwt.sign({ username: username }, SECRET_KEY);
        res.json({ token: token });
    } else {
        res.status(401).json({ message: 'Invalid username or password' });
    }
});

// Route to access protected resource
app.get('/protected', authenticateToken, (req, res) => {
    res.json({ message: 'This is a protected message' });
});

function authenticateToken(req, res, next) {
    const token = req.headers['authorization'];
    if (token == null) return res.sendStatus(401);
    jwt.verify(token, SECRET_KEY, (err, user) => {
        if (err) return res.sendStatus(403);
        req.user = user;
        next();
    });
}

app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});

