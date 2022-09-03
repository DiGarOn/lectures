export module C:A;
import :A;
export import :B;

//при импорте раздела видны все его части, вне зависимости от того, экспортируются они или нет 

//сопрограммы на с++ реализованы как функции, контекст которых хранится во внещнем объекте и камять под него хранится в куче
//co_await
//co_yield
//co_return

//тип возвращаемого значения сопрограммы должен:
//  1) содержать std::coroitine_handle<> (из <coroutine>);
//  2) корректно уничтожаться
//  3) содержать вложенный тип ::promise_type (std::coroutine_handle <promise_type>::from_promise(*this))
//      1) initial_suspen() - возврат std::suspend_never or std::suspend_always
//      2) final_suspendal() - 
//      3) void unhandled_exception()
//      4) void return_void() - либо void return_value(type)
//      5) get_return_object()
//      7) yield_value(type)
//      8) await_transform(type)
//  4)  

/*
auto switch_to_new_thread(std::jthread & out) {
    struct awaitable {
        void await_suspend(std::corautine_nadle<> h) {
            if(out.joinable())
            out = std::jthread([h](){h.resume();});
        }
    };
    return awaitable{&out};
}
*/