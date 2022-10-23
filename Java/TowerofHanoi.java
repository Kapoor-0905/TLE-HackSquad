public class TowerofHanoi
{
    public static void towerofHanoi(int n,char src,char help,char to)
    {
        if(n==1)
        {
            System.out.println("Move dist 1 from "+src+" to "+to);
            return;
        }
        towerofHanoi(n-1,src,to,help);
        System.out.println("Move disk "+n+" from "+src+" to "+to);
        towerofHanoi(n-1,help,src,to);
    }
    public static void main(String args[])
    {
        int n=4;
        towerofHanoi(n,'A','B','C');
    }
}
