open Jest;

open MomentRe;

let () =
  describe
    "moment"
    (
      fun () => {
        test "validity" (fun () => Just (Equal true (Moment.isValid (moment "2017-01-01"))));
        test "invalidity" (fun () => Just (Equal false (Moment.isValid (moment ""))));
        test "dst" (fun () => Just (Equal false (Moment.isDST (moment "2016-01-01T00:00:00"))));
        test "leap year" (fun () => Just (Equal true (Moment.isLeapYear (moment "2016-01-01"))));
        test
          "not leap year" (fun () => Just (Equal false (Moment.isLeapYear (moment "1900-01-01"))));
        test
          "instantiation"
          (fun () => Just (Truthy (Moment.isSame (moment "2017-04-01") (moment "2017-04-01"))));
        test
          "instantiation with format"
          (
            fun () =>
              Just (
                Equal
                  true
                  (
                    Moment.isSame
                      (moment format::"YYYY-MM-DD" "2017-04-01")
                      (moment format::"YYYY-MM-DD" "2017-04-01")
                  )
              )
          );
        test
          "now" (fun () => Just (Truthy (Moment.isSameOrBefore (moment_now ()) (moment_now ()))))
      }
    );
