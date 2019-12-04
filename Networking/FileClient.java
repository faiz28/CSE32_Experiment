import java.io.*;
import java.net.*;

public class FileClient {
	public static void main(String[] arg) {
		try {
			Socket socket = new Socket("localhost",2343);
			DataOutputStream dout = new DataOutputStream(socket.getOutputStream());
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String str;
			str = br.readLine();
			dout.writeUTF(str);

			File file=new File(str);
			long file_size=(long) file.length() ;
			String siz=String.valueOf(file_size);
			dout.writeUTF(siz);

			dout.flush();
			FileInputStream fos = new FileInputStream(str);
			byte [] buffer = new byte[4096];
			
			while(fos.read(buffer)>0) {
				dout.write(buffer);
			}
			
			dout.close();
			socket.close();
		}catch(Exception ex) {
			System.out.println(ex);
		}
	}
}
