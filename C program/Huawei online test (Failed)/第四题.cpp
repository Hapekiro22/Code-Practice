#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    double scorePerCreditA = *(double *)a;
    double scorePerCreditB = *(double *)b;
    return (scorePerCreditA > scorePerCreditB) - (scorePerCreditA < scorePerCreditB);
}

double my_fmax(double a, double b) {
    return (a > b) ? a : b;
}

int main() {
    int w, k;
    scanf("%d %d", &w, &k);

    double totalCreditsRequired = 0;
    double totalScoreRequired = 0;
    double scores[1000], credits[1000], credits1[1000], scores1[1000],scores2[1000];

    for (int i = 0; i < k; i++) {
        scanf("%lf %lf", &scores[i], &credits[i]);
        totalCreditsRequired += credits[i];
        totalScoreRequired += scores[i] * credits[i];
    }

    for (int i = 0; i < w - k; i++) {
        scanf("%lf %lf", &scores1[i], &credits1[i]);
    }

    for (int i = 0; i < w-k; i++) {
    	scores2[i] = scores1[i];
        scores1[i] /= credits1[i];
    }
    qsort(scores1, w, sizeof(double), cmp);
    
    for (int i = 0; i < w-k; i++)
    {
    	scores1[i] = scores2[i];
	}

    double maxPossibleScore = totalScoreRequired / totalCreditsRequired;
    for (int i = 0; i < w - k; i++) {
        double currentScore = (totalScoreRequired + scores1[i] * credits1[i]) / (totalCreditsRequired + credits1[i]);
        maxPossibleScore = my_fmax(maxPossibleScore, currentScore);
    }

    printf("%.2f\n", maxPossibleScore);

    return 0;
}
