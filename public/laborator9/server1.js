const express = require('express');
const bodyParser = require('body-parser');
const mongoose = require('mongoose');

const app = express();
const PORT = 3000;

// Conectare la baza de date MongoDB
mongoose.connect('mongodb://192.168.37.37/activitati', {
    useNewUrlParser: true,
    useUnifiedTopology: true
}).then(() => {
    console.log("Conectat la baza de date MongoDB.");
}).catch(err => {
    console.error("Eroare de conectare la baza de date:", err);
    process.exit();
});

// Definirea modelului pentru activitati
const activitySchema = new mongoose.Schema({
    user: Number,
    week: Number,
    activities: [String]
});

const Activity = mongoose.model('Activity', activitySchema);

app.use(bodyParser.json());

// Ruta pentru afișarea tuturor activităților
app.get('/activities', async (req, res) => {
    try {
        const activities = await Activity.find();
        res.json(activities);
    } catch (err) {
        res.status(500).json({ message: err.message });
    }
});

// Ruta pentru înregistrarea unei noi activități
app.post('/activities', async (req, res) => {
    const activity = new Activity({
        user: req.body.user,
        week: req.body.week,
        activities: req.body.activities
    });

    try {
        const newActivity = await activity.save();
        res.status(201).json(newActivity);
    } catch (err) {
        res.status(400).json({ message: err.message });
    }
});

app.listen(PORT, () => {
    console.log(`Serverul ascultă pe portul ${PORT}`);
});
