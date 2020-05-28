## Алгоритм Джея Кадана

### Задача

Поиск подотрезка массива с максимальной/минимальной суммой ("maximum subarray problem")

### Постановка задачи

Дан массив чисел a[1 <= n].Требуется найти такой его подотрезок a[l <= r], что сумма на нём максимальна.
Для задачи о поиске минимального подотрезка необходимо изменить знаки всех чисел на противоположные.

### Реализация

Алгоритм, который ищет только ответ, не фиксирует границы отрезка:

```
const int MaxArr = 300003;
ll mas[MaxArr];

int n;
cin >> n;

for (int i = 0; i < n; i++)
    cin >> mas[i];

ll ans = mas[0], sum = 0, min = 0;
for (int i = 0; i < n; ++i)
{
    sum += mas[i];
    ans = max(ans, sum);
    sum = max(sum, min);
}

cout << ans << endl;
```

Алгоритм, который ищет не только ответ, но и фиксирует границы отрезка:

```
const int MaxArr = 300003;
ll mas[MaxArr];

int n;
cin >> n;

for (int i = 0; i < n; i++)
    cin >> mas[i];

ll ans = mas[0], ans_l = 0,
   ans_r = 0, sum = 0, min = 0, minus_pos = -1;
for (int i = 0; i < n; ++i)
{
    sum += mas[i];
    if (sum > ans)
    {
        ans = sum;
        ans_l = minus_pos + 1;
        ans_r = i;
    }

    if (sum < 0)
    {
        sum = 0;
        minus_pos = i;
    }
}

cout << ans << " " << ans_l << " " << ans_r << endl;
```
