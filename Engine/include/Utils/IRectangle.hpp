#ifndef IRECTANGLE_H
#define IRECTANGLE_H


class IRectangle {
public:
    IRectangle();
    IRectangle(int x,int y,int w, int h);
    virtual ~IRectangle();
    int x;
    int y;
    int w;
    int h;
protected:
private:
};

#endif // IRECTANGLE_H
