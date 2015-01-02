/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb1;

import java.util.Arrays;

/**
 *
 * @author master
 */
public class Name implements Comparable {

    String firstName;
    String lastName;

    Name(String last_name, String first_name) {
        this.firstName = first_name;
        this.lastName = last_name;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null)
            return false;
        if (!(o instanceof Name))
            return false;
        Name other = (Name) o;
        
        return (this.firstName.equals(other.firstName) &&
                this.lastName.equals(other.lastName));
    }

    @Override
    public int compareTo(Object o) {
        if (o == null)
            throw new NullPointerException();
        if (!(o instanceof Name))
            throw new ClassCastException("Not comparable!");
        Name other = (Name) o;
        
        
        if (this.lastName.equals(other.lastName)) {
            return this.firstName.compareTo(other.firstName);
        }
        else {
            return this.lastName.compareTo(other.lastName);
        }
    }
    
    @Override
    public String toString() {
        String result = "";
        result = this.firstName + " " + this.lastName;
        
        return result;
    }

    public static void main(String[] args) {
        Name array[] = {
            new Name("Popa", "Mihai"),
            new Name("Pop", "Vasile"),
            new Name("Popa", "Mihaela")
        };
        
        Arrays.sort(array);
        for (Name a : array) {
            System.out.println(a);
        }
    }
}