//Utility function for constructing Cone
//Radius is the radius of the base
//height is the height of cone
//color are used for coloring
void Cone(double radius, double height, double color)
{
	for (int i = 0; i < SHARPNESS_FACTOR; ++i)
	{
		double th = (360.0 / SHARPNESS_FACTOR) * i;
		glBegin(GL_LINES);
		glColor3f(color, color, color);
		glVertex3f(radius * cos(th), radius * sin(th), 0);
		glColor3f(color, color, color);
		glVertex3f(0, 0, height);
		glEnd();
	}
}

//Utility function for constructing ThreeDtriangle
//base_length is the length of the base
//height is the height of triangle
//y_span is the thickness of triangle
//c1,c2 are used for coloring
void ThreeDtriangle(double base_length, double height, double y_span, double c1, double c2)
{
	// Samne wala Face
	for (int i = 0; i <= SHARPNESS_FACTOR; i++)
	{
		glBegin(GL_LINES);
		glColor3f(c1, c1, c1); //Base Color
		glVertex3f(((double)i * base_length) / SHARPNESS_FACTOR - base_length / 2, 0.0, 0.0);
		glColor3f(c2, c2, c2);
		glVertex3f(0.0, 0.0, height);
		glEnd();
	}

	// Picheka Face
	for (int i = 0; i <= SHARPNESS_FACTOR; i++)
	{
		glBegin(GL_LINES);
		glColor3f(c1, c1, c1); //Base Color
		glVertex3f(((double)i * base_length) / SHARPNESS_FACTOR - base_length / 2, y_span, 0.0);
		glColor3f(c2, c2, c2);
		glVertex3f(0.0, y_span, height);
		glEnd();
	}

	// Side  Face
	for (int i = 0; i <= SHARPNESS_FACTOR; i++)
	{
		glBegin(GL_LINES);
		glColor3f(c2, c2, c2);
		glVertex3f(-1 * base_length / 2, (double)i * y_span / SHARPNESS_FACTOR, 0.0);
		glColor3f(c2, c2, c2);
		glVertex3f(0.0, (double)i * y_span / SHARPNESS_FACTOR, height);
		glEnd();
	}

	//Side Face
	for (int i = 0; i <= SHARPNESS_FACTOR; i++)
	{
		glBegin(GL_LINES);
		glColor3f(c2, c2, c2);
		glVertex3f(base_length / 2, (double)i * y_span / SHARPNESS_FACTOR, 0.0);
		glColor3f(c2, c2, c2);
		glVertex3f(0.0, (double)i * y_span / SHARPNESS_FACTOR, height);
		glEnd();
	}
}

//Utility Function for constructing TriangularWing
//base_length is the length of base of 3d triangle
//small_length is the height of smaller 3d triangle
//large_height is the height of larger 3d triangle
//y_span is the thickness of wing
//epoch is the intial angular offset of rotation about z-axis
void TriangularWing(double base_length, double small_height, double large_height, double y_span, double epoch)
{

	// Chota wala triangle
	glLoadIdentity();
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(scale, scale, scale);
	glRotatef(world_y, 0.0, 1.0, 0.0);
	glTranslatef(.0, -0.03, -0.065);
	glRotatef(-wing_z + epoch, 0.0, 0.0, 1.0);
	glRotatef(60, 1.0, 0.0, 0.0);
	glTranslatef(-1.4 * small_height, 0.0, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	ThreeDtriangle(base_length, small_height, y_span, 1.0, 0.6);

	// Bada wala Triangle
	glLoadIdentity();
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(scale, scale, scale);
	glRotatef(world_y, 0.0, 1.0, 0.0);
	glTranslatef(.0, -0.03, -0.065);
	glRotatef(-wing_z + epoch, 0.0, 0.0, 1.0);
	glRotatef(60, 1.0, 0.0, 0.0);
	glTranslatef(-1.4 * small_height, 0.0, 0.0);
	glRotatef(270, 0.0, 1.0, 0.0);
	ThreeDtriangle(base_length, large_height, y_span, 1.0, 0.6);
}

//Utility Function for Constructing Shaft
//r_bottom is bottom radius
//r_top is top radius
//height is the height of staff
void Shaft(double r_bottom, double r_top, double height)
{
	for (int i = 0; i < SHARPNESS_FACTOR; ++i)
	{
		double th = (2 * PI / SHARPNESS_FACTOR) * i;
		glBegin(GL_LINES);
		double c = .7 + cos(th) * .2;
		glColor3f(c, c, c);
		glVertex3f(r_top * cos(th), r_top * sin(th), 0);
		glVertex3f(r_bottom * cos(th), r_bottom * sin(th), height);
		glEnd();
	}
}
