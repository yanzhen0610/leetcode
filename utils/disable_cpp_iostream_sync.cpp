static const auto disable_cpp_iostream_sync = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
