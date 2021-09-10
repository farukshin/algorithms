# algorithms

[Road Map (алгоритмы для проработки)](/roadMap.md)

## Алгоритмы

### Теория чисел

* [Бинарное возведение в степень](/theory/binpow.md)
* [Примитивы](/theory/primitivy.md)
* [MODINT](/theory/MODINT.md)
* [Длинная арифметика](/theory/da.md), [вариант 2](/theory/da2.md)
* [Решето Эратосфена](/theory/eratosfen.md) | [с линейным временем](/theory/eratosfen_n.md)
* [Диофантовы уравнения с двумя неизвестными](/theory/diafant.md)
* [Код Грея](/theory/gray.md)
* [Алгоритм BPSW - проверка числа на простоту](/theory/bpsw.md)
* [Факторизация числа](/theory/factorize.md)
* [Вычисление факториала по модулю](/theory/factmod.md)
* [Нахождение степени делителя факториала](/theory/step_factor.md)
* [Медиана онлайн](/theory/med_online.md)
* [Перебор всех подмасок данной маски](/theory/mask.md)

### Вычислительная геометрия
* [База по вычислительной геометрии](/theory/calc_geometry.md)

### Динамическое программирование

* [Теория и примеры](/theory/dynamic.md)
* [Динамика по профилю. Задача "Паркет"](/theory/dp_profile.md)

### Графовые алгоритмы

* [Общие понятия](/theory/graf.md)
* [Обход в ширину (не рекурсивный)](/theory/graf/bfs.md)
* [Поиск компонент связности](/theory/graf/bfsCompSv.md)
* [Поиск мостов (offline)](/theory/bridge.md)
* [Алгоритм Дейкстры](/theory/graf/dejkstra.md)
* [Топологическая сортировка графа](/theory/graf/topologicSort.md)
* [Алгоритм Флойда - Уоршелла (нахождения кратчайших путей между всеми парами вершин)](/theory/graf/Floyd_Warshall.md)
* [Алгоритм Форда-Беллмана](/theory/graf/FordBellman.md)
* Минимальный остов [Алгоритм Крускала](/theory/graf/Kruskal.md), [Алгоритм Прима](/theory/graf/prim.md), [Алгоритм Крускала с DSU](/theory/graf/Kruskal_dsu.md)
* [ms-sr](/theory/graf/ms_to_sr.md) | [ms-ss](/theory/graf/ms_to_ss.md) | [sr-ms](/theory/graf/sr_to_ms.md) | [ss-ms](/theory/graf/ss_to_ms.md)
* [Поиск истоков и стоков](/theory/graf/istok_stok.md)
* [Транзитивное замыкание](/theory/graf/transitive_closure.md)
* [read_ss](/theory/graf/read_ss.md) | [read_ss_from_ms](/theory/graf/read_ss_from_ms.md)
* [Поиск циклов отрицательного веса](/theory/graf/cycle.md)

#### компоненты связности

* [Поиск компонент сильной связности, построение конденсации графа за O(N+M)](/theory/graf/scc.md)

#### потоки
* [Нахождение максимального потока. Алгоритм Диница](/theory/graf/dinic.md)

#### наименьший общий предок (LCA)
* [Наименьший общий предок. Алгоритм Тарьяна (офлайн режим)](/theory/graf/lca_offline.md)

### Строковые алгоритмы

* [Z функция](/theory/zFunction.md)
* [Префикс-функция](/theory/prefix_function.md)
* [Нахождение всех подпалиндромов. Алгоритм Манакера](/theory/manaker.md)
* [Редакционное растояние](/theory/EditDistance.md). Алгоритмы: [Левенштейна]((/theory/Levenshtein.md)), Хэмминга, Дамеруа-Левенштейна, Джаро-Винклера


### Алгоритмы на последовательностях
* [Нахождение наидлиннейшей возрастающей подпоследовательности](/theory/maxsubarray.md)
* [K-ая порядковая статистика](/theory/nth_element.md)


### Структуры

* [Дерево Фенвика](/theory/fenwick.md)
* [DSU Система непересекающихся множеств](/theory/dsu.md)
* Нахождение минимума в [стеке](/theory/stack_min.md) и в [очереди](/theory/queue_min.md) за O(1)
* [Sqrt-декомпозиция](/theory/sqrt.md)
* [Sparse Table](/theory/sparse.md)
* [Декартово дерево (treap)](/theory/treap.md), [Декартово дерево по неявному ключу](/theory/treapImplicit.md)

### Сортировка

* [Общие понятия](/theory/sort.md)
* [Сортировка выбором](/theory/sort/selection-sort.md)

### Комбинаторика

* [Размещения, перестановки, сочетания](/theory/kombinator.md)
* [Правильные скобочные последовательности](/theory/skobki.md)

### Шахматы

* [pq-конь](/theory/pq_horse.md)

### Битовые операции

* [Битовые операции](/theory/bit.md)
* [Динамика по битовым маскам](/theory/bit_dp.md)

### Прочее

* [RobotPath](/theory/RobotPath.md)
* [Спираль](/theory/spiral.md)
* [Задача Иосифа](/theory/joseph.md)
* [Мажорирующий элемент](/theory/major.md)
* [SuperMemo](/theory/supermemo.md)

### Эвристические алгоритмы
* [Алгоритм отжига](/theory/otjig.md)

## Языки программирования

* [C++](./languages/cpp/README.md)
* * [Базовые типы данных](/languages/cpp/base_type.md)
* * [Структуры данных](/theory/data-structure.md)
* * [Массивы](/languages/cpp/array.md)
* * [Vector](/languages/cpp/vector.md)

## C++
* [Новый возможности в С++17](./stl/newcpp17.md)
* [Константы](./stl/const.md)

## C++ STL
* Контейнеры STL
  * [Vector](./stl/vector.md)
  * [Вставляем в map эффективно и по условию (try_emplace)](./stl/try_emplace.md)
  * [Семантика подсказок для вставки элементов std::map::insert](./stl/map_insert_it.md)
  * [Эффективно изменяем ключи элементов std::map extract](./stl/extract.md)
  * [Применяем контейнер std::unordered_map для пользовательских типов](./stl/unordered_map.md)
  * [Отсеиваем повторяющиеся слова в пользовательском вводе (set)](./stl/set.md)
  * [Подсчитываем частоту встречаемости слов map](./stl/map_count.md)
  * [Подсчет предложений и вывод в порядке длины, multimap](./stl/multimap_count.md)
  * [Список дел с приоритетом](./stl/proirity_queue.md)
* Итераторы
  * [Создание итерабельного диапазона данных](./stl/iter_item.md)
  * [Совместимость собственного итерабельного диапазона данных с STL](./stl/iter_item_sovm.md)
  * [Заполнения обобщенных структур данных](./stl/load_struct.md)
  * [Числа Фибоначчи с итераторами](./stl/fib_iter.md)
  * [Перебор в обратную сторону с применением обратных адаптеров](./stl/reverse_iter.md)

## Прочее
* [TCP vs UDP](./theory/tcp_udp.md)
