class Box
{
    double width;
    double hieght;
    double depth;
}

class BoxDemo{
    public static void main(String args[]){
        Box mybox = new Box();

        double vol;

        mybox.width = 10;
        mybox.hieght = 20;
        mybox.depth = 30;

        vol=mybox.width*mybox.hieght*mybox.depth;
        System.out.println("Volume is " +vol);

    }
}   