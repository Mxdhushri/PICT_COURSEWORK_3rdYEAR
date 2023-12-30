import java.rmi.*;
import java.io.*; 
public class RMIClient
{   
    public static void  main(String args[])
    { 
    try
      { BufferedReader br=new BufferedReader(new InputStreamReader(System.in)); //Scanner sc=new Scanner(System.in);
      MyInterface p=( MyInterface)Naming.lookup("rmiInterface");
        System.out.println("Type something..."); 
        String input=br.readLine(); //String input=sc.nextline();
        System.out.println(p.countInput(input)); 
            }
        catch(Exception e) { 
            System.out.println("Exception occurred : "+e.getMessage());
        }
    } 
 } 