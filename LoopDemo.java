class LoopDemo
{
	public static void main(String args[])
	{
		int num;
		num=100;
		System.out.println("Num="+num);
		for(int i=1;i<3;i++)
		{
			num=num*2;
			System.out.println("Num*2="+num);
		}
		System.out.println("Num="+num);
	}
}