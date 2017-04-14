
//小明到达公司的时间由三部分组成：起床时间，等车时间，车的行驶时间
//起床时间是固定的s。
//等车时间取决于起床时间s与发车间隔interval。如果s%interval为0，则等车时间是0；否则等车时间是(interval - s%interval)。
//车的行驶时间，包括停车时间与行驶时间，即(停站数 + 1) * 5分钟 + 停站数*停车时间。
//取等车时间 + 行驶时间的最小值即可，返回时记得加上起床时间。

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