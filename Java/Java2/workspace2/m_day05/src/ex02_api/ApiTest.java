package ex02_api;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class ApiTest {
	
	// 오늘의 당첨 로또 번호를 뽑는 메소드
	static void getLottoNum() {
		
		// 랜덤한 정수를 만드는 메소드가 들어있는 클래스
		Random random = new Random();
		
		ArrayList<Integer> lotto = new ArrayList<>();
		int lottoNum = 0;
		
		while(lotto.size() < 5) {
			lottoNum = random.nextInt(45) + 1;
			if(!lotto.contains(lottoNum)) {
				lotto.add(lottoNum);
			}
		
		}
		
		Collections.sort(lotto);
		System.out.println(lotto);
		
	}

	public static void main(String[] args) {

		// 카톡방에 올라온 new_lotto_api 추가해서(build path)
		// 본인의 로또번호 뽑은후 카톡방에 올리기
			
		Lotto lotto = new Lotto();
//		lotto.buyLotto();
		
		ApiTest.getLottoNum();
	
		
		
	}

}
