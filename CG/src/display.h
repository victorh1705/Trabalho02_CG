// Globals
float desiredFPS = 30;
int width  = 1000;
int height = 700;

void reshape (int w, int h)
{
    width = w;
    height = h;
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
}
