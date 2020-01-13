#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED


template <class T> class Rectangle : public Shape<T> {
  T x, y, length, width;
public:
    rectangle():x(0),y(0),length(0),width(0) {};
    rectangle(T _x, T _y, T _length, T _width): x(_x),y(_y),length(_length),width(_width){};

    virtual T getX() const(return x);
    virtual T getY() const {return y;}
    virtual T getWidth()  const {return length;}
    virtual T getHeight() const {return width;}
    virtual T getArea() const {return length*width;}


#endif // RECTANGLE_H_INCLUDED
