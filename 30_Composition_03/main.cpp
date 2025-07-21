#include <iostream>
#include <math.h>

using namespace std;

class Point {
private:
    int _x, _y;

public:
    Point(int x, int y)
        : _x(x)
        , _y(y)
    {
    }

    int GetX() {
        return _x;
    }

    int GetY() {
        return _y;
    }
};

class Line {
private:
    Point _pt1, _pt2; // Composition;

public:
    Line(int pt1x, int pt1y, int pt2x, int pt2y)
        : _pt1(pt1x, pt1y), _pt2(pt2x, pt2y) {
    }

    Line(Point pt1, Point pt2)
        : _pt1(pt1), _pt2(pt2) {
    }

    float GetLength() {
        int xBase = _pt2.GetX() - _pt1.GetX();
        int height = _pt1.GetY() - _pt2.GetY();

        return sqrt(pow(xBase, 2) + pow(height, 2));
    }
};

// �ﰢ�� Ŭ���� (���� �ﰢ��)
// �簢�� Ŭ���� (���� �簢��)
// �� Ŭ����

// ������ ����Ŭ������ ����� ������ ����ؼ� ����غ�����..

class Triangle
{
private:
    Point _leftBottomPt, _topPt, _rightBottomPt;

public:
    Triangle(Point leftBottomPt, Point rightBottomPt, Point topPt)
        : _leftBottomPt(leftBottomPt)
        , _topPt(topPt)
        , _rightBottomPt(rightBottomPt)
    {
    }

    Triangle(int  leftBottomPtX, int leftBottomPtY,
             int         topPtX, int topPtY,
             int rightBottomPtX, int rightBottomPtY)
        : _leftBottomPt(leftBottomPtX, leftBottomPtY)
        , _topPt(topPtX, topPtY)
        , _rightBottomPt(rightBottomPtX, rightBottomPtY)
    {
    }

    float GetArea()
    {
        int XBase = _rightBottomPt.GetX() - _leftBottomPt.GetX(); // �غ�
        int height = abs(_leftBottomPt.GetY() - _topPt.GetY());   // ����

        return XBase * height * 1 / 2;
    }
};

class Rectangle
{
private:
    Point _topLeftPt, _bottomRightPt;

public:
    Rectangle(Point topLeftPt, Point bottomRightPt)
        : _topLeftPt(topLeftPt)
        , _bottomRightPt(bottomRightPt)
    {
    }

    int GetArea()
    {
        int width = _bottomRightPt.GetX() - _topLeftPt.GetX();
        int high = _topLeftPt.GetY() - _bottomRightPt.GetY();

        return width * high;
    }
};

class Cycle
{
private:
    Point _centerPt; // �߽���
    int _radius;     // ������
    const float PI = 3.14;

public:
    Cycle(int centerPtX, int centerPtY, int radius)
        : _centerPt(centerPtX, centerPtY), _radius(radius) {
    }

    Cycle(Point centerPt, int radius)
        : _centerPt(centerPt), _radius(radius) {
    }

    Cycle(Point centerPt, Point edgePt)
        : _centerPt(centerPt)
    {
        Line line(centerPt, edgePt);
        _radius = line.GetLength();
    }

    Cycle(int centerPtX, int centerPtY, int edgePtX, int edgePtY)
        : _centerPt(centerPtX, centerPtY)
    {
        Line line(centerPtX, centerPtY, edgePtX, edgePtY);

        _radius = line.GetLength();
    }

    float GetArea() {
        return PI * _radius * _radius;
    }
};

int main() {
    Line line(0, 0, 4, 4);

    cout << "line length = " << line.GetLength() << endl;

    Triangle triangle(Point(2, 0), Point(4, 0), Point(0, 6));
    cout << "�ﰢ�� ���� = " << triangle.GetArea() << endl;

    Rectangle rectangle(Point(0, 4), Point(4, 0));
    cout << "�簢�� ���� = " << rectangle.GetArea() << endl;

    Cycle cycle(Point(0, 0), Point(5, 5));
    cout << "�� ���� = " << cycle.GetArea() << endl;

    return 0;
}