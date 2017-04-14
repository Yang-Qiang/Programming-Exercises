
//С�����﹫˾��ʱ������������ɣ���ʱ�䣬�ȳ�ʱ�䣬������ʻʱ��
//��ʱ���ǹ̶���s��
//�ȳ�ʱ��ȡ������ʱ��s�뷢�����interval�����s%intervalΪ0����ȳ�ʱ����0������ȳ�ʱ����(interval - s%interval)��
//������ʻʱ�䣬����ͣ��ʱ������ʻʱ�䣬��(ͣվ�� + 1) * 5���� + ͣվ��*ͣ��ʱ�䡣
//ȡ�ȳ�ʱ�� + ��ʻʱ�����Сֵ���ɣ�����ʱ�ǵü�����ʱ�䡣

public class TakeBuses {
	public int chooseLine(int[] stops, int[] period, int[] interval, int n, int s) {
		// write code here
		int min = Integer.MAX_VALUE;
		for (int i = 0;i<n;i++) {
			int missTime = s%interval[i];
			int waitCost = missTime == 0 ? 0 : interval[i] - missTime;
			min = Math.min(min, waitCost + (stops[i] + 1) * 5 + stops[i] * period[i]);
		}
		return min + s;
	}