import java.io.*;
import java.util.StringTokenizer;
import java. math.BigInteger;

public class StockMaximize
{
      public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      public static void main(String[] args) throws Exception
      {
            int t = Integer.parseInt(br.readLine());
            func(t);
      }
      public static void func(int t) throws Exception
      {
            while(t > 0)
            {
                  int n = Integer.parseInt(br.readLine());
                  int[] arr = new int[n];
                  int[] last = new int[n];
                  int[] sell = new int[n];
                  int i,j,k,count;
                  long cP = 0,sP = 0,profit = 0;
                  //BigInteger cP = new BigInteger(0),sP = new BigInteger(0) , profit = new BigInteger(0);
                  for(i = 0 ; i < n ; i++)
                  {
                        last[i] = -1;
                  }
                  StringTokenizer st = new StringTokenizer(br.readLine());
                  i = 0 ;
                  while(st.hasMoreTokens())
                  {
                        arr[i++] = Integer.parseInt(st.nextToken());
                  }
                  last[0] = 0;
                  sell[0] = 0;
                  j = 0;
                  for(i = 1 ; i < n ; i++)
                  {

                        if(arr[i] >= arr[last[j]])
                        {
                              k = j;
                              if(k < 0)
                                    break;
                              while(k > -1)
                              {
                                    if(arr[i] >= arr[last[k]])
                                    {
                                          sell[last[k]] = 0;
                                          j--;
                                    }
                                    else{
                                          j++;
                                          break;
                                    }
                                    k--;
                              }
                              //System.out.println("j = " + j);
                              if(j < 0)
                                    j = 0;
                              last[j] = i;
                              sell[i] = 1;
                        }
                        else if((arr[i] < arr[last[j]]) && (arr[i] < arr[i - 1]))
                        {
                              sell[i] = 0;
                        }
                        else{
                              j++;
                              last[j] = i;
                              sell[i] = 1;
                        }
                  }
                  /*
                  for(i = 0; i < n ; i++)
                  {
                        System.out.println(sell[i]);
                  }

                  System.out.println("------------------");

                  for(i = 0; i <= j ; i++)
                  {
                        System.out.println(last[i]);
                  }
                  System.out.println("------------------");
                  */
                  //cP = sP = count = 0;
                  k = 0;
                  i = 0;
                  //profit = 0;
                  count = 0;

                  while(k <= j)
                  {
                        //cP = new BigInteger(0);
                        //sP = new BigInteger(0);
                        cP = sP = 0;
                        count = 0;
                        while(i <= last[k] - 1)
                        {
                              if(arr[i] <= arr[last[k]])
                              {
                                    cP = cP + arr[i];
                                    count++;
                              }
                              //cP.add(new BigInteger(arr[i]));

                              i++;
                        }

                        sP = sP + count * arr[i];
                        //sP.add(new BigInteger(count * arr[i]));
                        //if(sP >= cP)
                              profit = profit + (sP - cP);
                        //profit.add(sP.subtract(cP));
                        //System.out.println(i + " " + i + "cp " + cP + " " + "sP " + sP);
                        i++;
                        k++;
                  }
                  System.out.println(profit);

                  t--;
            }
      }
}
