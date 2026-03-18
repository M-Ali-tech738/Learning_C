#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

// ── Constants ────────────────────────────────────────────────────────────────
const int W = 800, H = 600;
float timer = 0.0f;
const float PI = 3.14159265f;

// ── Stars ────────────────────────────────────────────────────────────────────
struct Star { float x, y, r, phase; };
const int NSTARS = 120;
Star stars[NSTARS];

void initStars() {
    srand(42);
    for (int i = 0; i < NSTARS; i++) {
        stars[i].x     = 40 + rand() % (W - 80);
        stars[i].y     = 40 + rand() % (H - 80);
        stars[i].r     = 0.6f + (rand() % 20) / 10.0f;
        stars[i].phase = (rand() % 628) / 100.0f;
    }
}

// ── Primitives ───────────────────────────────────────────────────────────────
void circle(float cx, float cy, float r, int seg = 80) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= seg; i++) {
        float a = 2 * PI * i / seg;
        glVertex2f(cx + r * cosf(a), cy + r * sinf(a));
    }
    glEnd();
}

void ring(float cx, float cy, float r1, float r2, int seg = 80) {
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= seg; i++) {
        float a = 2 * PI * i / seg;
        glVertex2f(cx + r1 * cosf(a), cy + r1 * sinf(a));
        glVertex2f(cx + r2 * cosf(a), cy + r2 * sinf(a));
    }
    glEnd();
}

void star5(float cx, float cy, float ro, float ri) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 10; i++) {
        float a = PI / 2 + i * PI / 5;
        float r = (i % 2 == 0) ? ro : ri;
        glVertex2f(cx + r * cosf(a), cy + r * sinf(a));
    }
    glEnd();
}

// ── Sky gradient ─────────────────────────────────────────────────────────────
void drawSky() {
    glBegin(GL_QUADS);
    glColor3f(0.02f, 0.01f, 0.10f); glVertex2f(0, 0); glVertex2f(W, 0);
    glColor3f(0.08f, 0.03f, 0.22f); glVertex2f(W, H); glVertex2f(0, H);
    glEnd();
}

// ── Twinkling stars ───────────────────────────────────────────────────────────
void drawStars() {
    for (int i = 0; i < NSTARS; i++) {
        float t = 0.4f + 0.6f * sinf(timer * 1.2f + stars[i].phase);
        glColor4f(1.0f, 0.97f, 0.85f, t);
        circle(stars[i].x, stars[i].y, stars[i].r);
    }
}

// ── Crescent moon ────────────────────────────────────────────────────────────
void drawMoon(float cx, float cy) {
    // glow
    glColor4f(1.0f, 0.95f, 0.4f, 0.08f); circle(cx, cy, 80);
    glColor4f(1.0f, 0.92f, 0.3f, 0.12f); circle(cx, cy, 65);
    // moon body
    glColor3f(1.0f, 0.90f, 0.25f); circle(cx, cy, 52);
    // cutout (crescent trick)
    glColor3f(0.05f, 0.02f, 0.16f); circle(cx + 22, cy + 8, 42);
    // star beside crescent
    glColor3f(1.0f, 0.88f, 0.3f);
    star5(cx + 68, cy + 24, 13, 5);
}

// ── Stained glass rose window ────────────────────────────────────────────────
void drawRoseWindow(float cx, float cy, float R) {
    int petals = 12;

    // Outer dark ring frame
    glColor4f(0.05f, 0.03f, 0.12f, 1.0f);
    ring(cx, cy, R * 0.95f, R * 1.05f);

    // Gold frame ring
    glColor4f(0.9f, 0.72f, 0.1f, 1.0f);
    ring(cx, cy, R * 0.90f, R * 0.95f);

    // Petal segments — alternating rich colors
    float colors[6][3] = {
        {0.8f, 0.15f, 0.15f},  // crimson
        {0.15f, 0.4f, 0.8f},   // sapphire
        {0.15f, 0.65f, 0.35f}, // emerald
        {0.75f, 0.3f, 0.75f},  // violet
        {0.85f, 0.55f, 0.1f},  // amber
        {0.1f, 0.6f, 0.7f},    // teal
    };

    for (int p = 0; p < petals; p++) {
        float a1 = 2 * PI * p / petals;
        float a2 = 2 * PI * (p + 1) / petals;
        float am = (a1 + a2) / 2;
        float* c = colors[p % 6];

        // outer petal
        glColor4f(c[0], c[1], c[2], 0.75f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx + R * 0.45f * cosf(am), cy + R * 0.45f * sinf(am));
        int steps = 20;
        for (int i = 0; i <= steps; i++) {
            float a = a1 + (a2 - a1) * i / steps;
            glVertex2f(cx + R * 0.88f * cosf(a), cy + R * 0.88f * sinf(a));
        }
        glEnd();

        // inner petal (opposite color)
        float* c2 = colors[(p + 3) % 6];
        glColor4f(c2[0], c2[1], c2[2], 0.8f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= steps; i++) {
            float a = a1 + (a2 - a1) * i / steps;
            glVertex2f(cx + R * 0.45f * cosf(a), cy + R * 0.45f * sinf(a));
        }
        glEnd();
    }

    // Spoke lines (lead came)
    glColor4f(0.05f, 0.03f, 0.12f, 1.0f);
    glLineWidth(2.5f);
    for (int p = 0; p < petals; p++) {
        float a = 2 * PI * p / petals;
        glBegin(GL_LINES);
        glVertex2f(cx, cy);
        glVertex2f(cx + R * 0.90f * cosf(a), cy + R * 0.90f * sinf(a));
        glEnd();
    }

    // Inner ring
    glColor4f(0.9f, 0.72f, 0.1f, 1.0f);
    ring(cx, cy, R * 0.42f, R * 0.47f);

    // Center jewel — pulsing
    float pulse = 0.85f + 0.15f * sinf(timer * 2.5f);
    glColor4f(1.0f * pulse, 0.88f * pulse, 0.2f * pulse, 1.0f);
    circle(cx, cy, R * 0.12f);
    glColor4f(1.0f, 1.0f, 0.8f, 0.9f);
    circle(cx, cy, R * 0.06f);

    // Outer decorative dots
    glColor4f(1.0f, 0.85f, 0.2f, 0.9f);
    for (int p = 0; p < petals * 2; p++) {
        float a = 2 * PI * p / (petals * 2);
        circle(cx + R * 0.97f * cosf(a), cy + R * 0.97f * sinf(a), 3.5f);
    }
}

// ── Lantern ──────────────────────────────────────────────────────────────────
void drawLantern(float x, float y, float sc, float r, float g, float b) {
    float flicker = 0.82f + 0.18f * sinf(timer * 4.5f + x * 0.05f);

    // Ambient glow
    glColor4f(r, g * 0.7f, 0.05f, 0.10f); circle(x, y, sc * 50);
    glColor4f(r, g * 0.8f, 0.1f,  0.15f); circle(x, y, sc * 35);

    // String
    glColor3f(0.85f, 0.7f, 0.15f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(x, y + sc * 42); glVertex2f(x, y + sc * 55);
    glEnd();

    // Top cap
    glColor3f(0.85f, 0.68f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(x - sc*15, y + sc*28); glVertex2f(x + sc*15, y + sc*28);
    glVertex2f(x + sc*11, y + sc*42); glVertex2f(x - sc*11, y + sc*42);
    glEnd();

    // Body
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x - sc*18, y - sc*26); glVertex2f(x + sc*18, y - sc*26);
    glVertex2f(x + sc*15, y + sc*28); glVertex2f(x - sc*15, y + sc*28);
    glEnd();

    // Decorative vertical stripes
    glColor4f(1.0f, 1.0f, 0.5f, 0.3f);
    glLineWidth(1.2f);
    for (int i = -1; i <= 1; i++) {
        glBegin(GL_LINES);
        glVertex2f(x + i * sc * 6, y - sc * 26);
        glVertex2f(x + i * sc * 6 * 1.15f, y + sc * 28);
        glEnd();
    }

    // Bottom cap
    glColor3f(0.85f, 0.68f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(x - sc*18, y - sc*26); glVertex2f(x + sc*18, y - sc*26);
    glVertex2f(x + sc*14, y - sc*36); glVertex2f(x - sc*14, y - sc*36);
    glEnd();

    // Flame
    glColor4f(1.0f, 0.95f * flicker, 0.25f * flicker, 1.0f);
    circle(x, y, sc * 7 * flicker);
    glColor4f(1.0f, 1.0f, 0.8f, 0.9f);
    circle(x, y, sc * 3);
}

// ── Mosque silhouette ─────────────────────────────────────────────────────────
void drawMosque() {
    glColor3f(0.04f, 0.02f, 0.13f);

    // Ground bar
    glBegin(GL_QUADS);
    glVertex2f(0, 0); glVertex2f(W, 0);
    glVertex2f(W, 55); glVertex2f(0, 55);
    glEnd();

    // Central dome
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(400, 55);
    for (int i = 0; i <= 60; i++) {
        float a = PI + i * PI / 60;
        glVertex2f(400 + 110 * cosf(a), 55 + 90 * sinf(a));
    }
    glEnd();
    // central tower
    glBegin(GL_QUADS);
    glVertex2f(382, 0); glVertex2f(418, 0);
    glVertex2f(418, 60); glVertex2f(382, 60);
    glEnd();

    // Left dome
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(220, 55);
    for (int i = 0; i <= 60; i++) {
        float a = PI + i * PI / 60;
        glVertex2f(220 + 65 * cosf(a), 55 + 55 * sinf(a));
    }
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(207, 0); glVertex2f(233, 0);
    glVertex2f(233, 58); glVertex2f(207, 58);
    glEnd();

    // Right dome
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(580, 55);
    for (int i = 0; i <= 60; i++) {
        float a = PI + i * PI / 60;
        glVertex2f(580 + 65 * cosf(a), 55 + 55 * sinf(a));
    }
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(567, 0); glVertex2f(593, 0);
    glVertex2f(593, 58); glVertex2f(567, 58);
    glEnd();

    // Minarets left
    glBegin(GL_QUADS);
    glVertex2f(60, 0); glVertex2f(78, 0);
    glVertex2f(78, 90); glVertex2f(60, 90);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(60, 90); glVertex2f(78, 90); glVertex2f(69, 115);
    glEnd();

    // Minarets right
    glBegin(GL_QUADS);
    glVertex2f(722, 0); glVertex2f(740, 0);
    glVertex2f(740, 90); glVertex2f(722, 90);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(722, 90); glVertex2f(740, 90); glVertex2f(731, 115);
    glEnd();

    // Gold outline on central dome
    glColor3f(0.9f, 0.72f, 0.1f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 60; i++) {
        float a = PI + i * PI / 60;
        glVertex2f(400 + 110 * cosf(a), 55 + 90 * sinf(a));
    }
    glEnd();
}

// ── Decorative border ────────────────────────────────────────────────────────
void drawBorder() {
    // Outer gold
    glColor3f(0.9f, 0.72f, 0.1f);
    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(15,15); glVertex2f(W-15,15);
    glVertex2f(W-15,H-15); glVertex2f(15,H-15);
    glEnd();

    // Inner thin
    glColor3f(0.7f, 0.5f, 0.08f);
    glLineWidth(1.5f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(22,22); glVertex2f(W-22,22);
    glVertex2f(W-22,H-22); glVertex2f(22,H-22);
    glEnd();

    // Corner stars
    glColor3f(1.0f, 0.85f, 0.2f);
    float cx[4] = {38, W-38, 38, W-38};
    float cy[4] = {38, 38, H-38, H-38};
    for (int i = 0; i < 4; i++) star5(cx[i], cy[i], 14, 6);

    // Edge dots
    glColor3f(0.9f, 0.72f, 0.1f);
    for (int i = 1; i < 16; i++) {
        float x = 15 + i * (W - 30) / 16.0f;
        circle(x, 15, 2.5f);
        circle(x, H - 15, 2.5f);
    }
    for (int i = 1; i < 12; i++) {
        float y = 15 + i * (H - 30) / 12.0f;
        circle(15, y, 2.5f);
        circle(W - 15, y, 2.5f);
    }
}

// ── Text ─────────────────────────────────────────────────────────────────────
void text(const char* s, float x, float y, void* font) {
    glRasterPos2f(x, y);
    for (int i = 0; s[i]; i++) glutBitmapCharacter(font, s[i]);
}

void drawText() {
    float pulse = 0.88f + 0.12f * sinf(timer * 1.8f);

    // Main heading
    glColor3f(1.0f * pulse, 0.88f * pulse, 0.22f * pulse);
    const char* h1 = "Eid Mubarak";
    float w1 = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)h1);
    text(h1, (W - w1) / 2.0f, 200, GLUT_BITMAP_TIMES_ROMAN_24);

    // Divider dots
    glColor3f(0.85f, 0.65f, 0.15f);
    for (int i = -3; i <= 3; i++)
        circle(W / 2.0f + i * 22, 188, i == 0 ? 4.5f : 2.5f);

    // Subtitle lines
    glColor3f(0.92f, 0.85f, 0.65f);
    const char* s1 = "May Allah accept our good deeds,";
    const char* s2 = "forgive our sins, and ease the suffering";
    const char* s3 = "of all people around the world.";
    float ws1 = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char*)s1);
    float ws2 = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char*)s2);
    float ws3 = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char*)s3);
    text(s1, (W - ws1) / 2.0f, 172, GLUT_BITMAP_HELVETICA_12);
    text(s2, (W - ws2) / 2.0f, 156, GLUT_BITMAP_HELVETICA_12);
    text(s3, (W - ws3) / 2.0f, 140, GLUT_BITMAP_HELVETICA_12);

    // Arabic dua
    glColor3f(0.75f, 0.58f, 0.2f);
    const char* dua = "Taqabbal Allahu Minna wa Minkum";
    float wd = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char*)dua);
    text(dua, (W - wd) / 2.0f, 118, GLUT_BITMAP_HELVETICA_12);
}

// ── Display ──────────────────────────────────────────────────────────────────
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    drawSky();
    drawStars();
    drawMosque();
    drawMoon(580, 490);

    // Rose window centered upper area
    drawRoseWindow(400, 390, 115);

    // Lanterns
    drawLantern(120, 310, 1.0f, 0.85f, 0.25f, 0.08f);  // red-gold left
    drawLantern(680, 310, 1.0f, 0.15f, 0.45f, 0.85f);  // blue right
    drawLantern(75,  430, 0.65f, 0.3f, 0.75f, 0.25f);  // green small
    drawLantern(725, 430, 0.65f, 0.75f, 0.25f, 0.65f); // purple small

    drawText();
    drawBorder();

    glDisable(GL_BLEND);
    glutSwapBuffers();
}

// ── Animation loop ───────────────────────────────────────────────────────────
void update(int) {
    timer += 0.025f;
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, W, 0, H);
    glMatrixMode(GL_MODELVIEW);
}

// ── Main ─────────────────────────────────────────────────────────────────────
int main(int argc, char** argv) {
    initStars();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(W, H);
    glutCreateWindow("Eid Mubarak");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}
