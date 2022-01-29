void specialKeys(int key, int x, int y)
{
  if (key == GLUT_KEY_RIGHT)
    world_y += r_amount;

  if (key == GLUT_KEY_LEFT)
    world_y -= r_amount;

  glutPostRedisplay();
}

void rotate()
{
  wing_z += wing_speed;

  glutPostRedisplay();
}

void mouseWheel(int button, int state, int x, int y)
{
  if (button == 3)
  {
    if (scale <= 3.0)
      scale += 0.03;
  }
  else if (button == 4)
  {
    if (scale >= 0.5)
      scale -= 0.03;
  }
}
