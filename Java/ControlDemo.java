class ControlDemo {
    public static void main(String args[])
    {
        int num1, num2;
        num1=3;
        num2=4;
        int sum;
        sum=num1+num2;
        System.out.println("Sum="+sum);
        for(int i=0; i<10;i++)
        {
            int pro=sum*i;
            System.out.println("Sum*"+i+"="+pro);
        }
    }
}
