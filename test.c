#include <GL/glut.h>
#include <freetype.h>
#include FT_FREETYPE_H

FT_Library ft;
FT_Face face;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    FT_Init_FreeType(&ft);
    FT_New_Face(ft, "testfont.ttf", 0, &face);
    FT_Set_Pixel_Sizes(face, 0, 48);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Set the color to black
    glRasterPos2f(0.1, 0.5);
    FT_GlyphSlot g = face->glyph;
    const char *text = "Funky Characters";
    for (const char *p = text; *p; p++) {
        if (FT_Load_Char(face, *p, FT_LOAD_RENDER))
            continue;
        glBitmap(g->bitmap.width, g->bitmap.rows, g->bitmap_left, g->bitmap_top, g->advance.x, 0, g->bitmap.buffer);
    }
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutCreateWindow("Developer Sticker");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


