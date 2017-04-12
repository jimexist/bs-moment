open Jest;

open MomentRe;

/* note that this is an interops test, not tests for moment.js itself, i.e. test comprehensiveness is not the goal */
let () = {
  describe
    "moment"
    (
      fun () => {
        test "#clone" (fun () => Just (Equal true (moment "2017-01-01" |> Moment.clone |> Moment.isValid)));
        test "#isValid" (fun () => Just (Equal true (moment "2017-01-01" |> Moment.isValid)));
        test "not #isValid" (fun () => Just (Equal false (moment "" |> Moment.isValid)));
        test
          "#isDST" (fun () => Just (Equal false (moment "2016-01-01T00:00:00" |> Moment.isDST)));
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
        test ".now" (fun () => Just (Equal true (moment_now () |> Moment.isValid)));
        test
          "#isSame"
          (
            fun () => Just (Equal true (Moment.isSame (moment "2016-01-01") (moment "2016-01-01")))
          );
        test
          "#isBefore"
          (
            fun () =>
              Just (Equal true (Moment.isBefore (moment "2016-01-01") (moment "2016-01-02")))
          );
        test
          "#isSameOrBefore"
          (
            fun () =>
              Just (Equal true (Moment.isSameOrBefore (moment "2016-01-01") (moment "2016-01-02")))
          );
        test
          "#isAfter"
          (
            fun () => Just (Equal true (Moment.isAfter (moment "2016-01-02") (moment "2016-01-01")))
          );
        test
          "#isSameOrAfter"
          (
            fun () =>
              Just (Equal true (Moment.isSameOrAfter (moment "2016-01-02") (moment "2016-01-01")))
          );
        test
          "#isBetween"
          (
            fun () =>
              Just (
                Equal
                  true
                  (
                    Moment.isBetween
                      (moment "2016-01-02") (moment "2016-01-01") (moment "2016-01-03")
                  )
              )
          );
        test
          "#format"
          (
            fun () => Just (Equal "2016-01-01" (moment "2016-01-01" |> Moment.format "YYYY-MM-DD"))
          );
        test /* TODO: test this time-zone independently */
          "#defaultFormat" (fun () => Just (Truthy (moment "2016-01-01" |> Moment.defaultFormat)));
        test
          "#valueOf" /* TODO: float? */
          (fun () => Just (Equal 1451606400000. (moment "2016-01-01 00:00:00Z" |> Moment.valueOf)))
        /* test TODO: time-zone
           "#toJSON"
           (
             fun () => Just (Equal "2015-12-31T16:00:00.000Z" (moment "2016-01-01" |> Moment.toJSON))
           ) */
      }
    );
  describe
    "moment duration"
    (
      fun () => {
        test "get duration" (fun () => Just (Truthy (duration 2 "d")));
        test "get duration millis" (fun () => Just (Truthy (duration_millis 2)));
        test "get duration format" (fun () => Just (Truthy (duration_format "P2D")));
        test
          "#milliseconds"
          (fun () => Just (Equal 2 (duration 2 "milliseconds" |> Duration.milliseconds)));
        test "#seconds" (fun () => Just (Equal 2 (duration 2 "seconds" |> Duration.seconds)));
        test "#asSeconds" (fun () => Just (Equal 2. (duration 2 "seconds" |> Duration.asSeconds)));
        test "#minutes" (fun () => Just (Equal 2 (duration 2 "minutes" |> Duration.minutes)));
        test "#asMinutes" (fun () => Just (Equal 2. (duration 2 "minutes" |> Duration.asMinutes)));
        test "#hours" (fun () => Just (Equal 2 (duration 2 "hours" |> Duration.hours)));
        test "#asHours" (fun () => Just (Equal 2. (duration 2 "hours" |> Duration.asHours)));
        test "#days" (fun () => Just (Equal 2 (duration 2 "days" |> Duration.days)));
        test "#asDays" (fun () => Just (Equal 2. (duration 2 "days" |> Duration.asDays)));
        test "#weeks" (fun () => Just (Equal 2 (duration 2 "weeks" |> Duration.weeks)));
        test "#asWeeks" (fun () => Just (Equal 2. (duration 2 "weeks" |> Duration.asWeeks)));
        test "#months" (fun () => Just (Equal 2 (duration 2 "months" |> Duration.months)));
        test "#asMonths" (fun () => Just (Equal 2. (duration 2 "months" |> Duration.asMonths)));
        test "#years" (fun () => Just (Equal 2 (duration 2 "years" |> Duration.years)));
        test "#asYears" (fun () => Just (Equal 2. (duration 2 "years" |> Duration.asYears)));
        test "#as" (fun () => Just (Equal 2. (duration 2 "d" |> Duration.asUnitOfTime `days)));
        test "#toJSON" (fun () => Just (Equal "P2D" (duration 2 "d" |> Duration.toJSON)));
        test "#humanize" (fun () => Just (Equal "2 days" (duration 2 "d" |> Duration.humanize)))
      }
    )
};
