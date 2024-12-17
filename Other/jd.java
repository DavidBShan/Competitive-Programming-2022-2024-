import java.util.Scanner;

public class jd {

    /**
     * @author Jackson Ding, Benjamin Sheng
     *         source 1:
     *         https://github.com/sjay05/CCC-Solutions/blob/master/2002/S5.cpp
     * @param args
     */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double x = input.nextInt();
        double y = input.nextInt();
        double p = input.nextInt();
        double q = input.nextInt();
        int ballBounceCount = 0;
        double[] initPoint = { p, 0 };

        double slope = q / (x - p);
        double currIntercept = getIntercept(initPoint, slope);

        double[] secondPoint = { x, q };
        ballBounceCount++;

        double[] lastPoint = secondPoint;

        for (int i = 0; i < 1000000; i++) {
            // System.out.println(lastPoint[0] + " " + lastPoint[1]);
            slope = -slope;
            currIntercept = getIntercept(lastPoint, slope);
            double[] nextPoint;
            double[] p1 = horizontalSolve(0, slope, currIntercept);
            double[] p2 = horizontalSolve(y, slope, currIntercept);
            double[] p3 = verticalSolve(0, slope, currIntercept);
            double[] p4 = verticalSolve(x, slope, currIntercept);
            if (p1[0] <= x && p1[0] >= 0 && lastPoint[0] != p1[0] && lastPoint[1] != p1[1]) {
                nextPoint = p1;
            } else if (p2[0] <= x && p2[0] >= 0 && lastPoint[0] != p2[0] && lastPoint[1] != p2[1]) {
                nextPoint = p2;
            } else if (p3[1] <= y && p3[1] >= 0 && lastPoint[0] != p3[0] && lastPoint[1] != p3[1]) {
                nextPoint = p3;
            } else if (p4[1] <= y && p4[1] >= 0 && lastPoint[0] != p4[0] && lastPoint[1] != p4[1]) {
                nextPoint = p4;
            } else {
                System.out.println(0);
                System.exit(0);
                nextPoint = new double[] { 0, 0 };
            }
            lastPoint = nextPoint;
            if (isInCorner(nextPoint, x, y)) {
                // System.out.println(nextPoint[0] + " " + nextPoint[1]);
                System.out.println(ballBounceCount);
                System.exit(0);
            } else {
                ballBounceCount++;
            }
        }
        System.out.println(0);
    }

    public static boolean isInCorner(double[] point, double x, double y) {
        double xPoint = roundToTwoDecimals(point[0]);
        double yPoint = roundToTwoDecimals(point[1]);
        //System.out.println(xPoint + " " + yPoint);
        if (xPoint == 0 || xPoint == x) {
            if ((yPoint <= y && yPoint > y - 5) || (yPoint < 5 && yPoint >= 0)) {
                return true;
            }
        } else if (yPoint == 0 || yPoint == y) {
            if ((xPoint <= x && xPoint > x - 5) || (xPoint < 5 && xPoint >= 0)) {
                return true;
            }
        }
        return false;
    }

    public static double[] verticalSolve(double v, double m, double b) {
        double y = m * v + b;
        return new double[] { v, y };
    }

    public static double[] horizontalSolve(double h, double m, double b) {
        double x = (h - b) / m;
        return new double[] { x, h };
    }

    public static double getIntercept(double[] point, double slope) {
        return point[1] - slope * point[0];
    }

    public static double roundToTwoDecimals(double value) {
        return Math.round(value * 100.0) / 100.0;
    }
}