package Geometry2D;
public class Circle extends Figure 
{
private static final String Name = "Круг";
private double r;
public Circle(double r)
{
this.radius = r;
}
public void show() 
{
System.out.println(fig.getName() + ": площадь = " + fig.getArea());
}
public double Area()
{
return 3.14d * r * r;
}
public String getName() 
{
return name;
}
}