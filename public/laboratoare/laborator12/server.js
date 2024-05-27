const express = require("express");
const http = require("http");
const socketIo = require("socket.io");

const app = express();
const server = http.Server(app);
const io = socketIo(server);

app.use(express.static(__dirname));

const data = [
    [
        { "x": 15, "y": 20.796944465148848 },
        { "x": 20, "y": -87.76071913378763 },
        { "x": 25, "y": 345.38945493018247 },
        { "x": 30, "y": -290.3588389731994 },
        // Adaugă mai multe date aici
        { "x": 360, "y": 423.5865895557995 },
        { "x": 365, "y": 289.1583173638684 }
    ]
];

app.get("/start", (req, res) => {
    console.log("start sending piece by piece..");
    res.send("start .. sending data..");
    let i = 0;
    const interval = setInterval(() => {
        const item = data[0][i];
        console.log(i, ": ", item);
        io.emit('chat', item);
        i++;
        if (i === data[0].length) clearInterval(interval);
    }, 1000);
});

io.on('connection', (socket) => {
    console.log('A user connected');
    socket.on('disconnect', () => {
        console.log('A user disconnected');
    });
});

server.listen(3013, () => {
    console.log("Well done, now I am listening on ", server.address().port);
});
