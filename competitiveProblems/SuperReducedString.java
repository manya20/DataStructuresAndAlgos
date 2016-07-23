import java.io.*;

public class SuperReducedString
{
      public static void main(String[] args) throws IOException
      {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringBuffer str = new StringBuffer(br.readLine());
            //System.out.println(str);
            //int i,j;
            StringBuffer st2 = new StringBuffer("mohit");
            //System.out.println(st2.delete(0,1));
            superReducedString(str);
      }
      public static void superReducedString(StringBuffer str)
      {
            int i = 0 ;
            while(i < str.length() - 1)
            {
                  if(str.charAt(i) == str.charAt(i + 1))
                  {
                        str = str.delete(i,i+2);
                        // = i + 2;
                        //
                        if(i != 0)
                              i = i - 1;
                        //System.out.println("inside.. i = : " + i);
                        continue;
                  }
                  //System.out.println("outside");
                  else
                        i++;
            }
            //System.out.println(str);
            if(str.length() > 1)
            {
                  System.out.println("i =" + i + " length = " + str.length());
                  if(str.charAt(i) == str.charAt(i - 1))
                  {
                        str = str.delete(i - 1,i + 1);
                  }
            }
            if(str.length() != 0)
                  System.out.println(str);
            else
                  System.out.println("Empty String");
      }
}
