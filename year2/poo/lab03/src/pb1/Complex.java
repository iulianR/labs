/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb1;

/**
 *
 * @author master
 */
public class Complex {
 
    private double re, im;
    
    public Complex(double re, double im) {
        this.re = re;
        this.im = im;
    }
    
    public Complex() {
        this.re = 0;
        this.im = 0;
    }
    
    public Complex add(Complex x) {
        return new Complex(this.re + x.re, this.im + x.im);
    }
    
    public Complex mul(Complex x) {
        Complex result = new Complex();
        result.re = this.re * x.re - this.im * x.im;
        result.im = this.re * x.im + x.re * this.im;
        return result;
    }
    
    public Complex power(int pow) {
        Complex result = new Complex();
        result.re = this.re;
        result.im = this.im;
        
        for (int i = 0; i < pow - 1; i++) {
            result = result.mul(this);
        }
        
        return result;
    }
    
    @Override
    public String toString() {
        if (im > 0) return re + "+" + im + "*i";
        return re + "" + im + " *i";
    }
    
    @Override
    public boolean equals(Object obj) {
        if (obj == null) return false;
        if (!(obj instanceof Complex)) return false;
        Complex comp = (Complex) obj;
        return (comp.re == re && comp.im == im);
    }
    
    public static void main(String args[]) {
        Complex a = new Complex (3, 2);
        Complex b = new Complex (3, 2);
        
        System.out.println(a.add(b));
        System.out.println(a.mul(b));
        System.out.println(a.equals(b));
        System.out.println(a.power(2));
    }
}
