//title: Value Compress
//prefix: compress
//description: Value Compress
sort($1.begin(), $1.end());
$1.erase(unique($1.begin(),$1.end()), $1.end());