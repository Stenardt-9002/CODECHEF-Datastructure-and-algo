import java.io.IOException;
import java.lang.Math;
public class Primepoly{
    public int reveal(int A,int B,int C)
    {
        int M=2;
        while(prime(A*M*M+B*M+C))
        {
            M++;
        }
        return M;
    }
    private boolean prime(int n)
    {
        if(n<2)
        {
            return false;
        }

        for(int i = 2;i<=Math.sqrt(n);i++)
        {
            if (n%i==0) {
                return false;

            }
        }
        return true;

    }

    public static void main(String[] args) throws IOException{
        Primepoly X1 = new Primepoly();


    }


}
