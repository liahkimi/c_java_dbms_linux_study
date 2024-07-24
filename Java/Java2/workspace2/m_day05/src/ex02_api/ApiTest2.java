package ex02_api;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.util.Arrays;

public class ApiTest2 {

	public static void main(String[] args) {

		// 외부 API
		
		// 번역하고 싶은 메세지
		String msg = "오늘은 애플주가가 상승했습니다";
		

		String clientId = "_FEzdoA715y98f2ptK24";// 애플리케이션 클라이언트 아이디값";
		String clientSecret = "MOP_EDYIY3";// 애플리케이션 클라이언트 시크릿값";
		try {
			String text = URLEncoder.encode(msg, "UTF-8");
			String apiURL = "https://openapi.naver.com/v1/papago/n2mt";
			URL url = new URL(apiURL);
			HttpURLConnection con = (HttpURLConnection) url.openConnection();
			con.setRequestMethod("POST");
			con.setRequestProperty("X-Naver-Client-Id", clientId);
			con.setRequestProperty("X-Naver-Client-Secret", clientSecret);
			// post request
			String postParams = "source=ko&target=de&text=" + text;
			con.setDoOutput(true);
			DataOutputStream wr = new DataOutputStream(con.getOutputStream());
			wr.writeBytes(postParams);
			wr.flush();
			wr.close();
			int responseCode = con.getResponseCode();
			BufferedReader br;
			if (responseCode == 200) { // 정상 호출
				br = new BufferedReader(new InputStreamReader(con.getInputStream()));
			} else { // 에러 발생
				br = new BufferedReader(new InputStreamReader(con.getErrorStream()));
			}
			String inputLine;
			StringBuffer response = new StringBuffer();
			while ((inputLine = br.readLine()) != null) {
				response.append(inputLine);
			}
			br.close();
			System.out.println(response.toString());

			String[] li = response.toString().split("\"");

			int num = Arrays.asList(li).indexOf("translatedText");
			System.out.println(li[num + 2]);

		} catch (Exception e) {
			System.out.println(e);
		}

	}
}