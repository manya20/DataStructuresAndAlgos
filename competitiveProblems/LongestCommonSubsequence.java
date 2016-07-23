import java.io.*;
import java.util.StringTokenizer;

public class LongestCommonSubsequence
{
      public static void main(String[] args) throws Exception
      {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st1 = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st1.nextToken());
            int m = Integer.parseInt(st1.nextToken());
            StringTokenizer st2  = new StringTokenizer(br.readLine());
            int[] arr1 = new int[n];
            int[] arr2 = new int[m];
            int i = 0;
            while(st2.hasMoreTokens())
            {
                  arr1[i++] = Integer.parseInt(st2.nextToken());
            }
            i = 0 ;
            StringTokenizer st3  = new StringTokenizer(br.readLine());
            while(st3.hasMoreTokens())
            {
                  arr2[i++] = Integer.parseInt(st3.nextToken());
            }
            LCS(arr1,n,arr2,m);

      }
      public static void LCS(int[] arr1,int n,int[] arr2,int m)
      {
            int[][] mat = new int[n + 1][m + 1];
            int i , j;
            i = 0;
            for(i = 0 ; i < n + 1 ; i++)
            {
                  mat[i][0] = 0;
            }
            i = 0;
            for(i = 0 ; i < m + 1 ; i++)
            {
                  mat[0][i] = 0;
            }
            for(i = 1 ; i < n + 1 ; i++)
            {
                  for(j = 1 ; j < m + 1 ; j++)
                  {
                        if(arr1[i - 1] == arr2[j - 1])
                        {
                              mat[i][j] = mat[i - 1][j - 1] + 1;
                        }
                        else
                        {
                              mat[i][j] = max(mat[i][j - 1],mat[i - 1][j]);
                        }
                  }
            }
            /*
            for(i = 0 ; i < n + 1 ; i++)
            {
                  for(j = 0 ; j < m + 1 ; j++)
                  {
                        System.out.print(mat[i][j] + " ");
                  }
                  System.out.println("");
            }
            */
            print(mat,arr1,n,arr2,m);
      }
      public static void print(int[][] mat,int[] arr1,int n,int[] arr2,int m)
      {
            int i = n,j = m;
            int length = mat[n][m];
            int[] arr = new int[length];
            int index = length - 1;
            //System.out.println("--------------------------------");
            while(i > 0 && j > 0)
            {
                  //System.out.println("i = " + i + "j = " + j);
                  if(arr1[i - 1] == arr2[j - 1])
                  {
                        arr[index] = arr1[i - 1];
                        index--;
                        i--;
                        j--;
                  }
                  else if(mat[i - 1][j] >= mat[i][j - 1])
                  {
                        i--;
                  }
                  else
                  {
                        j--;
                  }
            }

            for(i = 0 ; i < length ; i ++)
            {
                  System.out.print(arr[i]  + " ");
            }
            }

      public static int max(int n,int m)
      {
            if(n >= m)
                  return n;
            else
                  return m;
      }
}
