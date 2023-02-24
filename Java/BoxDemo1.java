class Box
{
    double width;
    double height;
    double depth;

    void volume()
    {
        System.out.println("volume is:"+(width*height*depth));
    }
}

class BoxDemo1{
    public static void main(String args[]){
        Box mybox = new Box();

        mybox.width = 10;
        mybox.height = 20;
        mybox.depth = 30;

        mybox.volume();

    }
}   