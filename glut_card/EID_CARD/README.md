# 🌙 Eid Mubarak Animated Greeting Card

An animated OpenGL/GLUT greeting card rendered in C++, featuring a stylized mosque skyline, twinkling stars, a crescent moon, glowing lanterns, and a stained-glass dome — built as a computer graphics project.

---

## ✨ Features

- **Animated night sky** — 110 randomly placed, softly twinkling stars
- **Crescent moon** — glowing halo effect with an embedded five-pointed star
- **Mosque silhouette** — central building with minarets and a stained-glass dome rendered in 8 colored panels
- **Flickering lanterns** — 4 lanterns at different scales with a real-time flicker animation
- **BMP logo overlay** — loads `eid_logo.bmp` with chroma-key transparency
- **Decorative border** — gold double-line frame with corner stars and dot ornaments
- **Dedication & name text** — rendered via GLUT bitmap fonts

---

## 🗂️ File Structure

```
.
├── eid_card_final.cpp   # Main source file
├── RGBA.h               # RGBApixmap helper class (BMP loader + chroma key)
├── eid_logo.bmp         # Logo image (must be in the working directory)
└── README.md
```

---

## 🛠️ Dependencies

| Dependency | Purpose |
|---|---|
| OpenGL | Core rendering |
| GLUT / FreeGLUT | Window management, bitmap fonts, timer |
| C++ Standard Library | `<cmath>`, `<cstdlib>` |

### Installing FreeGLUT

**Ubuntu/Debian:**
```bash
sudo apt install freeglut3-dev
```

**macOS (Homebrew):**
```bash
brew install freeglut
```

**Windows:**
Download FreeGLUT from [freeglut.sourceforge.net](http://freeglut.sourceforge.net) and link accordingly.

---

## 🔨 Building & Running

### Linux / macOS
```bash
g++ eid_card_final.cpp -o eid_card -lGL -lGLU -lglut -lm
./eid_card
```

### Windows (MinGW)
```bash
g++ eid_card_final.cpp -o eid_card.exe -lfreeglut -lopengl32 -lglu32
eid_card.exe
```

> **Note:** `eid_logo.bmp` must be present in the same directory as the executable, otherwise the logo will not render.

---

## 🖼️ Window

| Property | Value |
|---|---|
| Resolution | 800 × 600 px |
| Title | `Eid Mubarak` |
| Rendering mode | Double-buffered RGBA |
| Animation interval | 25 ms (~40 FPS) |



## 👤 Credits

- **Author:** Muhammad Ali  
- **Seat No:** B25110206026  
- **Dedicated to:** Ms. Humaira Tariq
