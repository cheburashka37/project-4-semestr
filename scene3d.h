#ifndef SCENE3D_H
#define SCENE3D_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include "tetgen.h"
#include "grav_calc.h"
#include <string.h>

class Scene3D : public QOpenGLWidget, protected QOpenGLFunctions
{
    private:

    GLfloat xRot;
    GLfloat yRot;
    GLfloat zRot;
    GLfloat zTra;
    GLfloat xTra;
    GLfloat nSca;
    GLfloat R;

    std::ifstream fin;
    tetgenio in, out;
    tetgenbehavior behavior;

    struct Arrow
    {
        GLfloat x1 = 1.0f;
        GLfloat y1 = 1.0f;
        GLfloat z1 = 1.0f;

        GLfloat x2 = 0.8f;
        GLfloat y2 = 0.8f;
        GLfloat z2 = 0.8f;
    };
    Arrow grav_Arrow;

    QPoint ptrMousePosition;
    
    void scale_plus();
    void scale_minus();
    void rotate_up();
    void rotate_down();
    void rotate_left();
    void rotate_right();
    void translate_down();
    void translate_up();
    void translate_left();
    void translate_right();

    void drawArrow();
    void drawAxisSegment();
    void drawAxis();
    void defaultScene();
    void drawFigure();
    void CalcPoint();


protected:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);

    void keyPressEvent(QKeyEvent* pe);
    void mousePressEvent(QMouseEvent* pe);
    void wheelEvent(QWheelEvent* pe);
    void mouseMoveEvent(QMouseEvent* pe);

   public:
      Scene3D(QWidget* parent = nullptr);
      int flag_arr, flag_pnt, flag_ans;
      REAL p[3], v[3];
      void paintGL();
      void free_scene3D();
      void my_getArrays(std::string path);
      std::string path;

};
#endif
