#include "cpr/payload.h"

#include <initializer_list>
#include <string>
#include "cpr/util.h"

namespace cpr {

Payload::Payload(const std::initializer_list<Pair>& pairs) : Payload(begin(pairs), end(pairs)) {}

int Payload::isEmpty() {
    return content.empty();
}

void Payload::AddPair(const Pair& pair) {
    if (!content.empty()) {
        content += "&";
    }
    auto escaped = cpr::util::urlEncode(pair.value);
    content += pair.key + "=" + escaped;
}

} // namespace cpr
