package Geometry3D;
import Geometry2D.*;
public class Cylinder
{
private static final String name = "Цилиндер";
private double width;
private Figure f;
public Cylinder(double width, Figure f)
{
this.width = width;
this.f = f;
}
public void show() 
{
System.out.println(fig.getName() + ": площадь = " + fig.getArea());
}
public double volume()
{
return f.area()*width;
}
public String GetName() 
{
return name;
}
}
