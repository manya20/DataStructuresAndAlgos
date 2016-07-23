//it didnt run for every testcases on Codecheff. and i cudnt find those testcases.
//but still it ran for many cases.


import java.io.*;
import java.util.StringTokenizer;

public class EasyLongestIncreasingSubsequence
{
      public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      public static void main(String[] args) throws Exception
      {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[] second = new int[n];
            int i = 0,max,j;
            while(st.hasMoreTokens())
            {
                  arr[i++] = Integer.parseInt(st.nextToken());
            }
            for(i = 1 ; i < n ;i++)
            {
                second[i] = second[i - 1];
                  for(j = i - 1 ; j >= 0 ; j--)
                  {
                        if(arr[j] < arr[i] )
                        {
                              //if(second[i] <= second[j])
                              //{
                                    second[i] = second[j] + 1;
                                    break;
                              //}
                        }


                  }
            }
            max = second[0];
            for(i = 1 ; i < n ; i++)
            {
                  if(max < second[i])
                  {
                        max = second[i];
                  }
            }
            /*
            System.out.println("-------------");
            for(i = 1 ; i < n ; i++)
           {
                 System.out.println(second[i]);
           }
           */
            if(max == 0)
                        System.out.println(max);
            else
                  System.out.println(max + 1);
      }
}
