package Geometry2D;
public class Rectangle extends Figure 
{
private static final String name = "Прямоугольник";
private double width;
private double height;
public Rectangle(double width, double height)
{
this.width = width;
this.height = height;
}
public void show() 
{
System.out.println(fig.getName() + ": площадь = " + fig.getArea());
}
public doule Area()
{
return width * height;
}
public String getName()
{
return name;
}
}