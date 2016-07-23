import java.util.StringTokenizer;
import java.io.*;
import java.util.Arrays;
public class MandragoraForest
{
      public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      public static void main(String[] args)throws  Exception
      {
            int t = Integer.parseInt(br.readLine());
            while(t > 0)
            {
                  int n = Integer.parseInt(br.readLine());
                  StringTokenizer st = new StringTokenizer(br.readLine());
                  long[] h = new long[n];
                  int i = 0;
                  while(st.hasMoreTokens())
                  {
                        h[i++] = Integer.parseInt(st.nextToken());
                  }
                  Arrays.sort(h);
                  long[] p = new long[n];
                  int[] s = new int[n];
                  int sCount = 1;
                  int pCount = 0;
                  if(n == 1)
                  {
                        return h[0] * sCount;
                  }

                  p[0] = pCount;
                  s[0] = ++sCount;

                  for(i = 1 ; i < n ; i++)
                  {
                        if(i == 1)
                        {

                        }
                  }

                  t--;
            }
      }
      public static int max(int n1,n2)
      {
            if(n1 >= n2)
                  return n1;
            else
                  return n2;
      }
}
