open Jest;

open MomentRe;

let () =
  describe
    "moment"
    (
      fun () => {
        test "validity" (fun () => Just (Equal true (moment "2017-01-01" |> Moment.isValid)));
        test "invalidity" (fun () => Just (Equal false (moment "" |> Moment.isValid)));
        test "dst" (fun () => Just (Equal false (moment "2016-01-01T00:00:00" |> Moment.isDST)));
        test "leap year" (fun () => Just (Equal true (moment "2016-01-01" |> Moment.isLeapYear)));
        test
          "not leap year"
          (fun () => Just (Equal false (moment "1900-01-01" |> Moment.isLeapYear)));
        test
          "instantiation"
          (
            fun () => Just (Equal true (Moment.isSame (moment "2017-04-01") (moment "2017-04-01")))
          );
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
          "now"
          (fun () => Just (Equal true (Moment.isSameOrBefore (moment_now ()) (moment_now ()))))
      }
    );
