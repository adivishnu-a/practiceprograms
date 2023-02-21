class IfDemo {
    public static void main(String args[]){
        int num1;//variable declaration 
        num1=100;//variable initialization 
        int num2=20;//single line declaration& initialization 
        if(num1>num2)//Relational operator-->boolean 
        { 
            System.out.println(num1+" Greater than "+num2); 
        }
        boolean votercard=true; 
        if(votercard) //boolean variable 
            System.out.println("You are elgible to vote"); 
        else 
            System.out.println("You are not elgible to vote"); 
    }
}
