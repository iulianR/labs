/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb3;

/**
 *
 * @author master
 */
public class Matrix {
    
    float a[][];
    int size;
    
    public Matrix (int size) {
        this.a = new float[size][size];
        this.size = size;
    }
    
    @Override
    public String toString() {
        String result = "";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result += a[i][j] + " ";
            }
            result += "\n";
        }
        
        return result;
    }
    
    public Matrix add(Matrix x) {
        Matrix result = new Matrix(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.a[i][j] = this.a[i][j] + x.a[i][j];
            }
        }
        return result;
    }
    
    public Matrix mul(Matrix x) {
        Matrix result = new Matrix(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    result.a[i][j] += this.a[i][k] * x.a[k][j];
                }       
            }
        }
        
        return result;
    }
    
    public Matrix power(int pow) {
        Matrix result = new Matrix(size);
        for (int i = 0; i < size; i++) {
            System.arraycopy(this.a[i], 0, result.a[i], 0, size);
        }
        for (int i = 0; i < pow - 1; i++) {
            result = result.mul(this);
        }
        return result;
    }
    
    public static void main(String args[]) {
        Matrix m1 = new Matrix(2);
        Matrix m2 = new Matrix(2);
        
        for (int i = 0; i < m1.size; i++) {
            for (int j = 0; j < m1.size; j++) {
                m1.a[i][j] = 1;
            }
        }
        for (int i = 0; i < m2.size; i++) {
            for (int j = 0; j < m2.size; j++) {
                m2.a[i][j] = 2;
            }
        }
        System.out.println(m1);
        System.out.println(m2);
        System.out.println(m1.add(m2));
        System.out.println(m1.mul(m2));
        System.out.println(m1.power(3));
    }
}
