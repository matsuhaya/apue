# 詳解UNIXプログラミング

「詳解UNIXプログラミング」のサンプルコードを管理するリポジトリです。
apueは Advanced Programming in the UNIX Environment の略です。

## ビルド方法

プログラムはヘッダとライブラリを利用してコンパイルします。
ヘッダとライブラリは、「詳解UNIXプログラミング」のサポートページからダウンロードできます。

```sh
$ curl -O http://www.apuebook.com/src.3e.tar.gz
$ tar xvfz src.3e.tar.gz
```

make します。

```sh
$ cd apue.3e
$ make
```

ヘッダとライブラリを任意の場所にコピーします。

```sh
$ cp include/apue.h /usr/local/include/
$ cp lib/libapue.a /usr/local/lib/

# Mac だと下記でいけた
$ cp include/apue.h /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/
$ cp lib/libapue.a /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib/
```

プログラムは、下記の通りにライブラリをリンクしてコンパイルしてください。

```sh
$ gcc -lapue fork.c
```
