file=$(find . -type f )
rm -rf tests
touch  tests
for i in $file;do
    echo "=============$i=============" >> tests
    ./a.out $i > t;
    diff $i t >> tests;
done
# #!/bin/bash

# # الحصول على قائمة الملفات
# files=$(find . -type f)

# # حذف المجلد "tests" إذا كان موجودًا
# rm -rf tests

# # إنشاء مجلد جديد "tests" لتخزين النتائج
# mkdir tests

# # تكرار لكل ملف
# for file in $files; do
#     echo "=============$file============="
#     ./a.out "$file" > t # تشغيل البرنامج مع الملف
#     diff "$file" t >> tests/diff_results.txt # مقارنة الملف الأصلي بالملف الناتج
# done

# # حذف الملف المؤقت "t"
# rm -f t
