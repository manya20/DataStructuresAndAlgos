import java.util.StringTokenizer;
import java.io.*;
public class NikitaAndTheGame
{
  public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  public static void main(String[] args) throws IOException
  {

    int t = Integer.parseInt(br.readLine());
    func1(t);

 }
 public static void func1(int t) throws IOException
 {
   while(t > 0)
   {
     int n = Integer.parseInt(br.readLine());
     long[] arr = new long[n];
     StringTokenizer st = new StringTokenizer(br.readLine());
     int i = 0;
     //long sum;
     while(st.hasMoreTokens())
     {
       arr[i++] = Integer.parseInt(st.nextToken());
     }
     long total = 0;
     for(i = 0 ; i < n ; i++)
     {
       total = total + arr[i];
     //  System.out.println("between");
     }
     System.out.println(func2(arr,0,n-1,0,total));
     t--;
   }
 }
 public static long func2(long[] arr,int left,int right,long points,long total)
 {
   if(total == 1)
    return points;
   if(left == right)
      return points;
    long half = (total / 2),sum = 0;
   for(int i = left ; i <= right ; i++)
   {
     sum = sum + arr[i];
     if(sum > half)
        return points;
     if(sum == half)
      {
        points++;
      //  System.out.println("points and i = " + points + " " + i);
        return (max(func2(arr,left,i,points,half),func2(arr,i + 1,right,points,half)));

      }
   }
  // System.out.println("here");
   return points;
 }
 public static long max(long num1,long num2)
 {
   if(num1 >= num2)
    return num1;
    else
      return num2;
 }
}
