package Geometry2D;
public class Circle extends Figure 
{
private static final String Name = "����";
private double r;
public Circle(double r)
{
this.radius = r;
}
public void show() 
{
System.out.println(fig.getName() + ": ������� = " + fig.getArea());
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