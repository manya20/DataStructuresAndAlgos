import java.io.*;
import java.util.StringTokenizer;

 class SubsetSumDP
{
      public static void main(String[] args) throws IOException
      {
            func();
      }
      public static void func() throws IOException
      {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int t = Integer.parseInt(br.readLine());
            int j,i;
            while(t > 0)
            {
                  StringTokenizer st1 = new StringTokenizer(br.readLine());
                  int n = Integer.parseInt(st1.nextToken());
                  int k = Integer.parseInt(st1.nextToken());
                  //System.out.println(n + " " + k);

                  int[] arr = new int[n];
                  StringTokenizer st2  = new StringTokenizer(br.readLine());
                   i = 0;
                  while(st2.hasMoreTokens())
                  {
                        arr[i++] = Integer.parseInt(st2.nextToken());
                  }
                  int[][] mat = new int[n + 1][k + 1];

                  for(i = 0 ; i  < n + 1 ; i++)
                  {
                        mat[i][0] = -1;
                  }
                  for(i = 0 ; i  < k + 1 ; i++)
                  {
                        mat[0][i] = -1;
                  }

                  for(i = 1 ; i < n + 1 ; i++)
                  {
                        for(j = 1 ; j < k + 1 ; j++)
                        {
                              int prev = mat[i - 1][j];
                              if(prev == 0)
                              {
                                    mat[i][j] = prev;
                              }
                              else
                              {
                                    if(prev == -1)
                                    {
                                          if(arr[i - 1] == j)
                                          {
                                                mat[i][j] = 0;
                                          }
                                          else if(arr[i - 1] > j)
                                          {
                                                mat[i][j] = -1;
                                          }
                                          else
                                          {
                                                mat[i][j] = j - arr[i - 1];
                                          }
                                    }
                                    else
                                    {
                                          if(arr[i - 1] == j)
                                          {
                                                mat[i][j] = 0;
                                          }
                                          else if(arr[i - 1] < j)
                                          {
                                                int prev2 = mat[i - 1][j - arr[i - 1]];
                                                if(prev2 == -1)
                                                {
                                                      mat[i][j] = prev;
                                                }
                                                else
                                                {
                                                      mat[i][j] = min(prev,prev2);
                                                }
                                          }
                                          else
                                          {

                                                int prev2 = mat[i - 1][arr[i - 1] - j];
                                                if(prev2 == -1)
                                                {
                                                      mat[i][j] = prev;
                                                }
                                                else
                                                {
                                                      mat[i][j] = min(prev,prev2);
                                                }


                                                mat[i][j] = prev;
                                          }

                                    }
                              }
                        }

                  }


                  int res = 0;
                  for(i = 1; i < n + 1 ; i++)
                  {
                        if(mat[i][k] == 0)
                        {
                              res = 1;
                              System.out.println(res);
                              return;
                        }
                  }
                  System.out.println(res);
                  System.out.println("sdfdf");
                  t--;
                  System.out.println("-----------");
                  for(i = 0 ; i < n + 1 ; i++)
                  {
                        for(j = 0 ; j < k + 1 ; j++)
                        {
                              System.out.print(mat[i][j] + " ");
                        }
                        System.out.println("");
                  }
            }

      }
      public static int min(int n,int m)
      {
            if(n <= m)
                  return n;
            else
                  return m;
      }
}
