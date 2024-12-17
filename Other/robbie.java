class Complex{
        double re;
        double im;
        public Complex(double v, double v1){
            re = v; im = v1;
        }
        public double modulus(){
            return Math.sqrt(re*re + im*im);
        }
 }
public class robbie{
    public static void main(String[] args){
        Complex c = new Complex(3,4);
        System.out.println(c.modulus());
    }
}