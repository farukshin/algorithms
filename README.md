# algorithms

[Road Map (алгоритмы для проработки)](/roadMap.md)

## Алгоритмы

### Теория чисел

* [Бинарное возведение в степень](/theory/binpow.md)
* [Примитивы](/theory/primitivy.md)
* [Длинная арифметика](/theory/da.md)
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
* [Алгоритм Крускала (построение минимального остовного дерева)](/theory/graf/Kruskal.md)
* [ms-sr](/theory/graf/ms_to_sr.md) | [ms-ss](/theory/graf/ms_to_ss.md) | [sr-ms](/theory/graf/sr_to_ms.md) | [ss-ms](/theory/graf/ss_to_ms.md)
* [Поиск истоков и стоков](/theory/graf/istok_stok.md)
* [Транзитивное замыкание](/theory/graf/transitive_closure.md)
* [read_ss](/theory/graf/read_ss.md) | [read_ss_from_ms](/theory/graf/read_ss_from_ms.md)

#### потоки
* [Нахождение максимального потока. Алгоритм Диница](/theory/graf/dinic.md)

#### наименьший общий предок (LCA)
* [Наименьший общий предок. Алгоритм Тарьяна (офлайн режим)](/theory/graf/lca_offline.md)

### Строковые алгоритмы

* [Z функция](/theory/zFunction.md)
* [Префикс-функция](/theory/prefix_function.md)
* [Нахождение всех подпалиндромов. Алгоритм Манакера](/theory/manaker.md)
* [Редакционное растояние](/theory/EditDistance.md). Алгоритмы: [Левенштейна]((/theory/Levenshtein.md)), Хэмминга, Дамеруа-Левенштейна, Джаро-Винклера


### Структуры

* [Дерево Фенвика](/theory/fenwick.md)
* [DSU Система непересекающихся множеств](/theory/dsu.md)
* Нахождение минимума в [стеке](/theory/stack_min.md) и в [очереди](/theory/queue_min.md) за O(1)
* [Sqrt-декомпозиция](/theory/sqrt.md)

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

### Эвристические алгоритмы
* [Алгоритм отжига](/theory/otjig.md)

## Языки программирования

* [C++](./languages/cpp/README.md)
* * [Базовые типы данных](/languages/cpp/base_type.md)
* * [Структуры данных](/theory/data-structure.md)
* * [Массивы](/languages/cpp/array.md)
* * [Vector](/languages/cpp/vector.md)

## C++ STL
* [Новый возможности в С++17](./stl/newcpp17.md)
* Контейнеры STL
  * [Vector](./stl/vector.md)
  * [Вставляем в map эффективно и по условию (try_emplace)](./stl/try_emplace.md)
  * [Семантика подсказок для вставки элементов std::map::insert](./stl/map_insert_it.md)
  * [Эффективно изменяем ключи элементов std::map extract](./stl/extract.md)
  * [Применяем контейнер std::unordered_map для пользовательских типов](./stl/unordered_map.md)
  * [Отсеиваем повторяющиеся слова в пользовательском вводе (set)](./stl/set.md)
  * [Подсчитываем частоту встречаемости слов map](./stl/map_count.md)
  * [Подсчет предложений и вывод в порядке длины, multimap](./stl/multimap_count.md)
