var play = false;

class Bubble {
    constructor() {
        this.r = random(10, 50);
        this.x = random(this.r, width - this.r);
        this.y = random(this.r, height-this.r);
        this.speed = random(1, 5);
        this.stepX = this.speed;
        this.stepY = this.speed;
    }

    move() {
        this.x += this.stepX;
        this.y += this.stepY;
    }

    bounce() {
        if (this.x >= width - this.r / 2 || this.x <= this.r / 2)
            this.stepX *= -1;
        if (this.y >= height - this.r / 2 || this.y <= this.r / 2)
            this.stepY *= -1;
    }

    display() {
        noStroke();
        fill(255);
        ellipse(this.x, this.y, this.r);
    }
}

var bubbles = [];

function setup() {
    createCanvas(600, 400);
    background(42);

    for (var i = 0; i < 100; i++)
        bubbles[i] = new Bubble();
}

function draw() {
    if (play) {
        background(42);
        
        for (var i = 0; i < bubbles.length; i++) {
            bubbles[i].move();
            bubbles[i].bounce();
            bubbles[i].display();
        }
    }
}

function mousePressed() {
    play = !play;
}
