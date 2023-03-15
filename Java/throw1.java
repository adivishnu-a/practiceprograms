class throw1
{
	public static void validate(int age)
	{
		if(age<18)
		{
			throw new ArithmeticException("Person not eligible");
		}	
		else
		{
			System.out.println("Person is eligible to vote!");	
		}
	}
	public static void main(String[] args)
	{
		try
		{
			validate(10);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}	
}