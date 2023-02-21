public class ForVar {
    public static void main(String args[]){
        int i;
        boolean task=false;
        i=0;
        for(;!task;)
        {
            System.out.println("i = "+i);
            if(i==10) task=true;
            i++;
        }
    }
}
